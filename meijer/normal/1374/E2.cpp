#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 2e9+10
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int n, m, k, t[MX], a[MX], b[MX];
int SA[MX], sm[MX][4], cnt[4];
int id[MX][4];

void moveSet(set<ii>& fr, set<ii>& st, int& sum, int size) {
  while(true) {
    if(st.sz < size && !fr.empty()) {
      sum += fr.begin()->first;
      st.insert(*fr.begin());
      fr.erase(fr.begin());
      continue;
    }
    if(st.sz > size && !st.empty()) {
      sum -= (*--st.end()).first;
      fr.insert(*--st.end());
      st.erase(--st.end());
      continue;
    }
    if(!st.empty() && !fr.empty() && (*--st.end()).first > fr.begin()->first) {
      sum += fr.begin()->first;
      sum -= (*--st.end()).first;
      st.insert(*fr.begin());
      fr.erase(fr.begin());
      fr.insert(*--st.end());
      st.erase(--st.end());
      continue;
    }
    break;
  }
}

void program() {
    cin>>n>>m>>k;
    RE(i,n) cin>>t[i]>>a[i]>>b[i];
    RE(i,n) SA[i]=i;
    sort(SA,SA+n, [](int i, int j) {
        return t[i]<t[j];
    });
    RE(i,4) sm[0][i] = 0;
    RE(i,n) {
      int bm=a[SA[i]]+b[SA[i]]*2;
      id[cnt[bm]][bm] = SA[i];
      cnt[bm]++;
      sm[cnt[bm]][bm] = sm[cnt[bm]-1][bm] + t[SA[i]];
    }

    int ans=INF;
    set<int> sAns;
    RE(iter, 2) {
      set<ii> fr, st;
      int sum=0;
      RE(i,n) {
        int bm=a[i]+b[i]*2;
        if(bm == 3) continue;
        fr.insert({t[i], i});
      }
      int cur=0;
      REI(both,0,cnt[3]) {
        int needed = max(k-both, 0);
        if(needed > min(cnt[1], cnt[2]))
          continue;
        if(both+2*(needed) > m)
          continue;
        while(cur < needed) {
          REP(i,1,3) {
            ii p = {t[id[cur][i]], id[cur][i]};
            fr.erase(p);
            if(st.count(p)) {
              sum -= p.fi;
            }
            st.erase(p);
          }
          cur++;
        }
        while(cur > needed) {
          cur--;
          REP(i,1,3) {
            ii p = {t[id[cur][i]], id[cur][i]};
            fr.insert(p);
          }
        }
        moveSet(fr, st, sum, m-both-2*(needed));
        if(st.sz != m-both-2*(needed))
          continue;
        ans = min(ans, sm[both][3]+sm[needed][1]+sm[needed][2]+sum);
        if(iter == 1 && ans == sm[both][3]+sm[needed][1]+sm[needed][2]+sum) {
          RE(i,needed) sAns.insert(id[i][1]+1);
          RE(i,needed) sAns.insert(id[i][2]+1);
          RE(i,both) sAns.insert(id[i][3]+1);
          for(auto it:st) sAns.insert(it.second+1);
          break;
        }
      }
    }

    if(ans==INF) ans=-1;
    cout<<ans<<endl;
    bool f=1; for(auto it:sAns) cout<<(f?"":" ")<<it, f=0; cout<<endl;
}