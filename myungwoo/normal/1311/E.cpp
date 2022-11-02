#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

/* Fast Integer IO */
template<typename T> inline T read(T &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<typename T, typename... Args> inline void read(T &x, Args& ...args){
	read(x); read(args...);
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

int T, N, K;
int A[5001], B[5001], P[5001];
vector <pii> arr;

void dfs(int s, int e, int d)
{
    int n = e-s+1;
    for (int i=1;i<n;i++){
        int j = n-1-i;
        int p = A[i]+A[j]+n-1;
        int q = B[i]+B[j]+n-1;
        if (d < p || d > q) continue;
        int v = d-n+1, x = -1;
        if (v-A[i] >= A[j] && v-A[i] <= B[j]) x = A[i];
        if (v-B[i] >= A[j] && v-B[i] <= B[j]) x = B[i];
        if (v-A[j] >= A[i] && v-A[j] <= B[i]) x = v-A[j];
        if (v-B[j] >= A[i] && v-B[j] <= B[i]) x = v-B[j];
        assert(x != -1);
        P[s+1] = s, dfs(s+1, s+i, x);
        if (j) P[s+i+1] = s, dfs(s+i+1, e, v-x);
        return;
    }
}

int main()
{
    int b = 2, c = 0, sum = 0;
    for (int i=1;i<5001;i++){
        if (i >= b) b <<= 1, c++;
        sum += c;
        A[i] = sum, B[i] = i*(i-1)/2;
    }
    for (read(T);T--;){
        read(N, K);
        if (K < A[N] || K > B[N]){ puts("NO"); continue; }
        puts("YES");
        dfs(1, N, K);
        for (int i=2;i<=N;i++) write(P[i]), putchar(i < N ? ' ' : '\n');
    }
}