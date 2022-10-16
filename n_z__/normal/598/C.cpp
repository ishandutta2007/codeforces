#include<bits/stdc++.h>
using namespace std;
#define pci pair<complex<long double>,int>
int main()
{
    vector<pci>v;
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        int y,z;
        cin>>y>>z;
        pci fsb;
	    fsb.first.real(y),fsb.first.imag(z),fsb.second=x;
        v.push_back(fsb);
    }
	sort(v.begin(),v.end(),[](pci a,pci b){return arg(a.first)<arg(b.first);});
	long double mj=4*acos(-1);
    int id=0;
    for(int x=0;x<v.size()-1;x++)
    if(arg(v[x+1].first)-arg(v[x].first)<mj)id=x,mj=arg(v[x+1].first)-arg(v[x].first);
    if(arg(v[0].first)+2*acos(-1)-arg(v[v.size()-1].first)<mj)cout<<v[0].second<<' '<<v[v.size()-1].second<<endl;
    else cout<<v[id].second<<' '<<v[id+1].second<<endl;
}