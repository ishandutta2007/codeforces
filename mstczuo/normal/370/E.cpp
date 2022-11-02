# include <iostream>
# include <cstdio>
using namespace std;

typedef pair<int,int> pii; 
#define x first
#define y second
const int maxn = 200005;
pii L[maxn], R[maxn];
int cnt[maxn], a[maxn], n;

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for(int i=0; i<n; i++) cin>>a[i];
	if(a[0]>1) return cout<<-1<<endl,0;
	
	L[0]=R[0]=make_pair(1,1);
	for(int i=1;i<n;i++) {
		L[i] = L[i-1]; L[i].y++; R[i] = R[i-1]; R[i].y++;
		if(L[i].y>5) L[i].x++, L[i].y=1;
		if(R[i].y>2) R[i].x++, R[i].y=1;
		if(a[i] && (L[i].x>a[i] || R[i].x<a[i]))
			return cout << -1 << endl, 0;
		if(a[i]) L[i]=max(L[i],make_pair(a[i],1));
		if(a[i]) R[i]=min(R[i],make_pair(a[i],5));
	}

	pii ans = R[n-1];
	if(ans.y == 1) ans.x--, ans.y=5;
	if(ans < L[n-1]) return cout<<-1<<endl,0;

	cout << ans.x << endl;
	a[n-1] = ans.x; cnt[ans.x] = 1;
	for(int i=n-2; i>=0; i--) {
		a[i] = min(a[i+1], R[i].first);
		if(cnt[a[i]] == 5) a[i]--;
		cnt[a[i]]++;
	}
	for(int i=0; i<n; i++) cout << a[i] << ' ';
	cout << endl;
	return 0;
}