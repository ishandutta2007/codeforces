#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,cnt[26][2],n,m;
string a,b,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        n=a.length(),m=b.length();
        for(int i=0;i<26;++i)
            cnt[i][0]=cnt[i][1]=0;
        for(int i=0;i<n;++i)
            ++cnt[a[i]-'A'][0];
        for(int i=0;i<m;++i)
            ++cnt[b[i]-'A'][1];
        ans.clear();
        bool flag=1;
        for(int i=0;i<26;++i)
            if(cnt[i][0]<cnt[i][1])
            {
                cout<<"NO\n";
                flag=0;
                break;
            }
        if(!flag)
            continue;
        for(int i=0;i<n;++i)
            if(cnt[a[i]-'A'][0]--<=cnt[a[i]-'A'][1])
                ans.push_back(a[i]);
        cout<<(ans==b? "YES":"NO")<<'\n';
    }
    return 0;
}