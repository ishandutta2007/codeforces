#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int MN=2e5+10;
string ss[MN];
vector<int> so[MN];

pair<int, int> sfa[MN];
int hi[MN];
int lo[MN];

char getc(int sf, int i){
    if (sfa[sf].S+i>=(int)ss[sfa[sf].F].size()){
        return 0;
    }
    else{
        return ss[sfa[sf].F][sfa[sf].S+i];
    }
}

const int N=1<<18;
int st[2*N];

void add(int i, int x){
    for (i+=N;i;i/=2){
        st[i]+=x;
    }
}
int sum(int a, int b){
    a+=N;
    b+=N;
    int su=0;
    while (a<=b){
        if (a%2) su+=st[a++];
        if (!(b%2)) su+=st[b--];
        a/=2;
        b/=2;
    }
    return su;
}

int v[3*MN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,qq;
    cin>>n>>qq;
    int su=0;
    for (int i=0;i<n;i++){
        cin>>ss[i];
        for (int ii=0;ii<(int)ss[i].size();ii++){
            so[i].push_back(ss[i][ii]);
        }
        su+=ss[i].size();
    }
    for (int a=1;a<=su;a*=2){
        vector<pair<pair<int, int>, pair<int, int> > > t;
        for (int i=0;i<n;i++){
            for (int ii=0;ii<(int)ss[i].size();ii++){
                if (ii+a<(int)ss[i].size()){
                    t.push_back({{so[i][ii], so[i][ii+a]}, {i, ii}});
                }
                else{
                    t.push_back({{so[i][ii], -1}, {i, ii}});
                }
            }
        }
        sort(t.begin(), t.end());
        //cout<<a<<endl;
        int id=0;
        for (int i=0;i<(int)t.size();i++){
            if (i&&(t[i].F!=t[i-1].F||a*2>su)) id++;
            so[t[i].S.F][t[i].S.S]=id;
            //cout<<t[i].F.F<<" "<<t[i].F.S<<" "<<ss[t[i].S.F].substr(t[i].S.S, su)<<endl;
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<(int)ss[i].size();ii++){
            sfa[so[i][ii]]={i, ii};
        }
    }
    /*
    for (int i=0;i<su;i++){
        cout<<i<<" "<<sfa[i].F<<" "<<sfa[i].S<<" "<<ss[sfa[i].F].substr(sfa[i].S, su)<<endl;
    }
    */
    for (int i=0;i<n;i++){
        lo[i]=0;
        hi[i]=su-1;
        for (int ii=0;ii<(int)ss[i].size();ii++){
            int mi=lo[i];
            int ma=hi[i];
            while (mi<=ma){
                int m=(mi+ma)/2;
                if (ss[i][ii]>=getc(m, ii)){
                    hi[i]=m;
                    mi=m+1;
                }
                else{
                    ma=m-1;
                }
            }
            mi=lo[i];
            ma=hi[i];
            while (mi<=ma){
                int m=(mi+ma)/2;
                if (ss[i][ii]>getc(m, ii)){
                    mi=m+1;
                    lo[i]=m+1;
                }
                else{
                    ma=m-1;
                }
            }
        }
        //cout<<ss[i]<<" "<<lo[i]<<" "<<hi[i]<<endl;
    }
    vector<pair<pair<int, int>, pair<int, int> > > qs;
    for (int i=0;i<qq;i++){
        int l,r,k;
        cin>>l>>r>>k;
        l--;
        r--;
        k--;
        qs.push_back({{l-1, k}, {i, -1}});
        qs.push_back({{r, k}, {i, 1}});
    }
    sort(qs.begin(), qs.end());
    int i2=0;
    for (auto q:qs){
        while (i2<=q.F.F){
            for (int i=0;i<(int)ss[i2].size();i++){
                add(so[i2][i], 1);
            }
            i2++;
        }
        //cout<<q.F.F<<" "<<q.S.S*sum(lo[q.F.S], hi[q.F.S])<<" "<<lo[q.F.S]<<" "<<hi[q.F.S]<<endl;
        v[q.S.F]+=q.S.S*sum(lo[q.F.S], hi[q.F.S]);
    }
    for (int i=0;i<qq;i++){
        cout<<v[i]<<'\n';
    }
}