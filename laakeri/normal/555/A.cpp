#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<int> chs[1010101];
int ch[101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int v=0;
    for (int i=1;i<=k;i++){
        int m;
        cin>>m;
        v+=m-1;
        for (int ii=0;ii<m;ii++){
            int a;
            cin>>a;
            ch[a]=i;
            chs[i].push_back(a);
        }
    }
    for (int i=1;i<=k;i++){
        if (chs[i][0]==1){
            for (int j=1;j<(int)chs[i].size();j++){
                if (chs[i][j]==j+1){
                    v-=2;
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<v+n-1<<endl;
}