#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int pos[100001];
int ic[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        cin>>ic[i];
        pos[ic[i]]=i;
    }
    ll v=0;
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        v+=(ll)pos[a]/(ll)k;
        v++;
        if (pos[a]>0){
            pos[a]--;
            int t=ic[pos[a]];
            pos[t]++;
            ic[pos[a]+1]=t;
            ic[pos[a]]=a;
        }
    }
    cout<<v<<endl;
}