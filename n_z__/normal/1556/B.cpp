#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001],b[100001];
main()
{
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        int q=0,w=0;
        for(int x=1;x<=n;x++)
        {
            int y;
            cin>>y;
            if(y&1)a[++q]=x;
            else b[++w]=x;
        }
        if(abs(q-w)>=2)cout<<-1<<endl;
        else{
            int ans1=0;
            if(q>=w)
            for(int x=1;x<=n;x++)
            if(x&1)ans1+=abs(a[(x+1)/2]-x);else ans1+=abs(b[x/2]-x);
            int ans2=0;
            if(w>=q)
            for(int x=1;x<=n;x++)
            if(x&1)ans2+=abs(b[(x+1)/2]-x);else ans2+=abs(a[x/2]-x);
            int ans=0;
            if(q>=w)ans=ans1/2;
            if(w>=q)ans=ans2/2;
            if(q==w)ans=min(ans1/2,ans2/2);
            cout<<ans<<endl;
        }
    }
}