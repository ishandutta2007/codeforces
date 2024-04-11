#include<bits/stdc++.h>
using namespace std;
class Point {
public:
	long long x, y;
	int q;
};
bool cmp(const Point &a, const Point &b) {
    if (a.x == 0) return a.q < b.q;
    if (b.x == 0) return a.q <= b.q;
    if (a.q != b.q) return a.q < b.q;
    bool sign = (a.x * b.x > 0);
    return (a.y * b.x < b.y * a.x) == sign;
}
long long cross(const Point &a, const Point &b){
	return a.x*b.y-b.x*a.y;
}
int n;
Point P[10005], Q[10005];
long long work(int id){
    int N = 0;
    for (int i = 1; i <= n; ++i) if (i != id) {
        ++N;
        P[N].x = Q[i].x - Q[id].x;
        P[N].y = Q[i].y - Q[id].y;
        if (P[N].x < 0) P[N].q = (P[N].y < 0 ? 1 : 4);
        else if (P[N].x > 0) P[N].q = (P[N].y < 0 ? 2 : 3);
        else P[N].q = (P[N].y < 0 ? 1 : 3);
    }
	sort(P + 1, P + N + 1, cmp);
	for(int i=1;i<=N;i++) P[N+i]=P[i];
	long long ans=(long long)N*(N-1)*(N-2)/6;
	for(int i=1,j=1;i<=N;i++){
		while(j<i+N&&cross(P[i],P[j])>=0) j++;
		long long k=j-i-1;
		ans-=k*(k-1)/2;
	}
	//cout << id << ' ' << ans << endl;
	return ans;
}
void read(void){
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> Q[i].x >> Q[i].y;
	}
}
int main(){
	read();
	long long ans = 0;
	for (int i = 1; i <= n; ++i) ans += work(i);
	//cout << ans << endl;
	cout << ans * (n - 4) / 2 << endl;
	return 0;
}