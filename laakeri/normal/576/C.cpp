#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<pair<int, int> > ps[1010];

int main(){
    int n;
    scanf("%d", &n);

    for (int i=0;i<n;i++){
        int x,y;
        scanf("%d%d", &x, &y);
        ps[y/1000].push_back({x, i+1});
    }
    vector<int> v;
    int k=0;
    for (int i=0;i<1010;i++){
        if (ps[i].size()>0){
            if (k%2==0){
                sort(ps[i].begin(), ps[i].end());
            }
            else{
                sort(ps[i].rbegin(), ps[i].rend());
            }
            for (auto p:ps[i]){
                v.push_back(p.S);
            }
            k++;
        }
    }
    for (int vv:v){
        printf("%d ", vv);
    }
    printf("\n");
}