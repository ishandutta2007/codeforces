#include <bits/stdc++.h>
using namespace std;
vector <int> rz;
char a[100005],b[100005];
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>t;
    while(t--)
    {
        rz.clear();
        cin>>n;
        cin>>(a+1)>>(b+1);
        int st=1,dr=n;
        for(int pz=1;pz<=n;++pz)
        {
            int pzc=n-pz+1;
            int vb=b[pzc]-'0';
            int va;
            int pa;
            if(pz%2)
                pa=st++;
            else
                pa=dr--;
            va=a[pa]-'0';
            if(pz%2==0)
                va=1-va;
            if(va==vb)
                rz.push_back(1);
            rz.push_back(n-pz+1);
        }
        cout<<rz.size()<<'\n';
        for(i=0;i<rz.size();++i)
        {
            cout<<rz[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}