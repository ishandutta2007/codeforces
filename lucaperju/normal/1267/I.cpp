#include <bits/stdc++.h>
using namespace std;
vector <int> vm,vM;
int v[202];
int query (int a, int b)
{
    cout<<"? "<<a<<' '<<b<<'\n';
    cout.flush();
    char c;
    cin>>c;
    if(c=='>')
        return a;
    else
        return b;
}
int main()
{
    long long n,m,i,j,x,y,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vm.clear();
        vM.clear();
        for(i=1;i<=n;++i)
        {
            int a=query(i*2-1,i*2);
            vM.push_back(a);
            vm.push_back(i*4-1-a);
        }
        for(i=1;i<=2*n;++i)
            v[i]=0;
        for(i=0;i<n;++i)
            for(j=i+1;j<n;++j)
                ++v[query(vm[i],vm[j])];
        for(i=0;i<n;++i)
            if(v[vm[i]]==n-1)
                break;
        int pz=i;
        for(i=0;i<n;++i)
            for(j=i+1;j<n;++j)
            {
                if(i==pz || j==pz)
                    continue;
                ++v[query(vM[i],vM[j])];
            }
        for(i=0;i<n;++i)
        {
            if(i==pz)
                continue;
            if(v[vM[i]]==n-2)
                break;
        }
        int pz1=i;
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)
            {
                if(j==pz1 || j==pz)
                    continue;
                query(vm[i],vM[j]);
            }
        }
        cout<<"! \n";
        cout.flush();
    }
    return 0;
}
/**
4
2 4 8 6 1 3 5 7
*/