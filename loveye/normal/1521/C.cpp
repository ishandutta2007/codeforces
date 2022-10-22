#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e5 + 5;
int n,p[N];
inline int query(int op,int i,int j,int x) {
	int res;
	cout << '?' << ' ' << op << ' ' << i << ' ' << j << ' ' << x << endl;
	cin >> res;
	return res;
}
bool vis[N];
vector<int> v;
I getans(int r1,int r2,int i,int j) {
	int r3 = query(1,i,j,r2);
	if(r3 == r2) p[i] = r1,p[j] = r2;
	else p[i] = r2,p[j] = r1;
	vis[r1] = vis[r2] = 1;
}
int main() {
	srand(time(0));
	int t;cin >> t;
	while(t--) {
		cin >> n;
		v.clear();
		fr(i,1,n) vis[i] = 0;
		for(int i = 1;i < n;i += 2) {
			int r1 = query(1,i,i+1,n-1),r2 = query(2,i,i+1,1);
			if(r1 >= n-1 || r2 <= 2) v.push_back(i),v.push_back(i+1);
			else getans(r1,r2,i,i+1);
		}
		if(n & 1) v.push_back(n);
		fo(i,1,n) if(!vis[i]) {
			random_shuffle(v.begin(),v.end());
			int ok = 0;
			fo(j,0,v.size()-1) {
				if(query(2,v[j],v[j+1],i) == i) {
					p[v[j]] = i;
					v.erase(v.begin() + j);
					ok = 1;
					break;
				}
			}
			if(!ok) p[v.back()] = i,v.erase(v.end() - 1);
		}
		p[v[0]] = n;
		cout << "! ";
		fr(i,1,n) cout << p[i] << ' ';
		cout << endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}