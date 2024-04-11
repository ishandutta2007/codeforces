#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    int n,m,c,q=0;
    cin>>n>>m>>c;
    while(m--&&q<=n)
    {
        int x;
        cin>>x;
        if(x>c/2)for(q=n;a[q]>=x;--q);
        else for(q=1;a[q]&&a[q]<=x;++q);
        cout<<q<<endl;
        fflush(stdout);
        a[q]=x;
        for(q=1;q<=n&&a[q];++q);
    }
}