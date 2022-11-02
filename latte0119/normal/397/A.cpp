#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;

int N;
int L[100],R[100];

bool ex[110];

int main(){
    cin>>N;
    rep(i,N)cin>>L[i]>>R[i];
    for(int i=1;i<N;i++){
        for(int j=L[i];j<R[i];j++)ex[j]=true;
    }
    int ans=0;
    for(int i=L[0];i<R[0];i++)ans+=!ex[i];
    cout<<ans<<endl;
    return 0;
}