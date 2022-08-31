#include <iostream>
#include <queue>
using namespace std;
    int freq[100010];
    priority_queue<pair<int,int> > pq;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < 100010; i++){
        freq[i] = 0;
    }

    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            for(int j = 0; j < 3; j++){
                if(pq.size() == 0) break;
                freq[pq.top().second]++;;
                pq.pop();
            }
            while(pq.size() > 0) pq.pop();
        } else {
            pq.push(make_pair(a[i],i));
        }
    }
    int b, c, d;
    d = b = c = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            int k = 0;
            if(b>0) k++;
            if(c>0) k++;
            if(d>0) k++;
            cout << k;
            if(b>0) cout << " popStack";
            if(c>0) cout << " popQueue";
            if(d>0) cout << " popFront";
            b=0;
            c=0;
            d=0;
            cout << endl;
        } else {
            if(freq[i] == 0){
                cout << "pushBack" << endl;
                continue;
            }
            if(b<=c && b <= d){
                b++;
                cout << "pushStack" << endl;
                continue;
            } else if(c <= d){
                c++;
                cout << "pushQueue" << endl;
                continue;
            } else {
                d++;
                cout << "pushFront" << endl;
                continue;
            }
        }
    }

    return 0;
}