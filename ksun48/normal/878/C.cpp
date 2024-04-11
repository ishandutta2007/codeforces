#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, k;
map<int, vector<int> > minvals;
map<int, vector<int> > maxvals;
map<int,int> sz;

void join(int a, int b){
    //cout << a << " " << b << endl;
    int newv = min(a, b);

    vector<int> newmin;
    vector<int> newmax;
    int newsz = sz[a] + sz[b];
    for(int j = 0; j < k; j++){
        newmin.push_back(min(minvals[a][j], minvals[b][j]));
        newmax.push_back(max(maxvals[a][j], maxvals[b][j]));
    }
    sz.erase(a); sz.erase(b);
    minvals.erase(a); minvals.erase(b);
    maxvals.erase(a); maxvals.erase(b);

    sz[newv] = newsz;
    minvals[newv] = newmin;
    maxvals[newv] = newmax;
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        vector<int> person;
        int a;
        for(int j = 0; j < k; j++){
            cin >> a;
            person.push_back(a);
        }
        a = person[0];

        minvals[a] = person;
        maxvals[a] = person;
        sz[a] = 1;
        // sort by last coordinate, minvals[0]
        while(1){
            auto minit = minvals.find(a);

            if(minit != minvals.begin()){
                auto min2 = minit;
                min2--;
                int b = min2->first;
                int merge = 0;
                for(int j = 0; j < k; j++){
                    if(maxvals[b][j] > minvals[a][j]){
                        merge = 1;
                    }
                }
                if(merge){
                    // actually merge
                    join(b,a);
                    a = min(a,b);
                    continue;
                }
            }

            if(1){
                auto min2 = minit;
                min2++;
                if(min2 == minvals.end()) break;
                int b = min2->first;

                int merge = 0;
                for(int j = 0; j < k; j++){
                    if(maxvals[a][j] > minvals[b][j]){
                        merge = 1;
                    }
                }
                if(merge){
                    join(a,b);
                    a = min(a,b);
                    continue;
                }                
            }

            break;
        }
        auto it5 = sz.end();
        it5--;
        cout << (it5->second) << endl;
    }
}