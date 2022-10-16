#include<bits/stdc++.h>
using namespace std;
int f[100001],g[100001];
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        for(int x=0;x<=n;x++)
        f[x]=g[x]=0;
        int fir=0,lst=0;
        for(int x=1;x<=n;x++)
        {
            int y;
            cin>>y;
            fir+=(!fir)*y;
            f[y]++;
            if(y==lst)g[y]+=2,ans++;
            lst=y;
        }
        sort(f+1,f+1+n);
        if(f[n]>(n+1)/2)cout<<-1<<endl;
        else{
            g[fir]++;
            g[lst]++;
            sort(g+1,g+1+n);
            cout<<ans+max(0,g[n]-ans-2)<<endl;
        }
	}
}