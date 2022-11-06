#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - 1)
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
const int N=1e6+69;
vector <pair<int,int>> vek[N];
multiset <pair<int,int>> S1,S2;
int n,k,m,suma,ile,wynik;

void popraw() {
    while(1) {
        if(ile>k) {
            auto it=S1.end();
            it--;
            pair <int,int> zm=(*it);
            S1.erase(it);
            S2.insert(zm);
            suma-=zm.first*zm.second;
            ile-=zm.second;
            continue;
        }
        if(!S2.empty()&&(*S2.begin()).second+ile<=k) {
            pair <int,int> zm=(*S2.begin());
            S1.insert(zm);
            suma+=zm.first*zm.second;
            ile+=zm.second;
            S2.erase(S2.begin());
            continue;
        }
        auto it=S1.end();
        if(S1.empty()){
            break;
        }
        it--;
        if(!S2.empty()&&S1.empty()==false&&(*S2.begin()).first<(*it).first) {
            pair<int,int> zm=(*S2.begin());
            S1.insert(zm);
            suma+=zm.first*zm.second;
            ile+=zm.second;
            assert(S2.size());
            S2.erase(S2.begin());
            continue;
        }
        break;
    }
}
void dod(pair<int,int> a) {
    S2.insert(a);
    popraw();
}

void usu(pair<int,int> a) {
    a.first*=-1;
    if(S2.find(a)!=S2.end())  {
        S2.erase(S2.find(a));
        popraw();
        return;
    }
    suma-=a.first*a.second;
    ile-=a.second;
    S1.erase(S1.find(a));
    popraw();
}

int query() {
    if(S2.empty()) return suma;
    return suma+(*S2.begin()).first*(k-ile);
}
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k>>m;
  for(int i=0;i<m;i++) {
    int a,b,l,r;
    cin>>l>>r>>a>>b;
    r++;
    vek[l].push_back(make_pair(b,a)); // cena, ilosc
    vek[r].push_back(make_pair(-b,a));
}
    for(int i=1;i<=n;i++) {
        while(vek[i].empty()==false) {
            if(vek[i].back().first<0) usu(vek[i].back());
            else dod(vek[i].back());
            vek[i].pop_back();
        }
        wynik+=query();
    }
    cout<<wynik<<endl;
}