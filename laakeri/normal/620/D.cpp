#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const ll inf=1e18;

ll a[2020];
ll b[2020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll sa=0;
    ll sb=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        sa+=a[i];
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>b[i];
        sb+=b[i];
    }
    ll v0=abs(sa-sb);
    pair<ll, pair<int, int> > v1={inf, {0, 0}};
    for (int i=0;i<n;i++){
        sa-=a[i];
        sb+=a[i];
        for (int ii=0;ii<m;ii++){
            sb-=b[ii];
            sa+=b[ii];
            v1=min(v1, {abs(sa-sb), {i, ii}});
            sb+=b[ii];
            sa-=b[ii];
        }
        sa+=a[i];
        sb-=a[i];
    }
    pair<ll, pair<int, int> > v2={inf, {0, 0}};
    if (n>1&&m>1){
        vector<ll> aa;
        vector<ll> bb;
        for (int i=0;i<n;i++){
            for (int ii=i+1;ii<n;ii++){
                aa.push_back(a[i]+a[ii]);
            }
        }
        for (int i=0;i<m;i++){
            for (int ii=i+1;ii<m;ii++){
                bb.push_back(b[i]+b[ii]);
            }
        }
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        int i2=(int)bb.size()-1;
        for (int i=0;i<(int)aa.size();i++){
            while (i2>0&&sa+2*bb[i2]-2*aa[i]-sb>0){
                i2--;
            }
            while (i2<(int)bb.size()-1&&sa+2*bb[i2]-2*aa[i]-sb<0){
                i2++;
            }
            //cout<<i<<" "<<i2<<" "<<sa+bb[i2]-aa[i]<<"<>"<<sb-bb[i2]+aa[i]<<endl;
            v2=min(v2, {abs((sa+bb[i2]-aa[i])-(sb-bb[i2]+aa[i])), {i, i2}});
            if (i2<(int)bb.size()-1){
                v2=min(v2, {abs((sa+bb[i2+1]-aa[i])-(sb-bb[i2+1]+aa[i])), {i, i2+1}});
            }
            if (i2>0){
                v2=min(v2, {abs((sa+bb[i2-1]-aa[i])-(sb-bb[i2-1]+aa[i])), {i, i2-1}});
            }
        }
    }
    if (v0<=v1.F&&v0<=v2.F){
        cout<<v0<<endl<<0<<endl;
    }
    else if(v1.F<=v2.F){
        cout<<v1.F<<endl<<1<<endl;
        cout<<v1.S.F+1<<" "<<v1.S.S+1<<endl;
    }
    else{
        vector<pair<ll, pair<int, int> > > aa;
        vector<pair<ll, pair<int, int> > > bb;
        for (int i=0;i<n;i++){
            for (int ii=i+1;ii<n;ii++){
                aa.push_back({a[i]+a[ii], {i, ii}});
            }
        }
        for (int i=0;i<m;i++){
            for (int ii=i+1;ii<m;ii++){
                bb.push_back({b[i]+b[ii], {i, ii}});
            }
        }
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        cout<<v2.F<<endl<<2<<endl;
        cout<<aa[v2.S.F].S.F+1<<" "<<bb[v2.S.S].S.F+1<<endl;
        cout<<aa[v2.S.F].S.S+1<<" "<<bb[v2.S.S].S.S+1<<endl;
    }
}