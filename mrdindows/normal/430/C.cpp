#include <bits/stdc++.h>
 
using namespace std;

typedef long long unsigned llu;
typedef long long lld;
typedef long ld;
 
//definition
#define vi vector < int >
#define vld vector < ld >
#define vlld vector < lld >
#define pi pair <int, int>
#define plld pair<lld, lld>
#define vpi vector< pi >
#define vplld vector< plld >
 
#define gc getchar_unlocked
#define pc putchar_unlocked
#define rr freopen("input.txt", "r", stdin)
#define wr freopen("output.txt", "w", stdout)
 
//important constants
#define MOD 1000000007
#define INF 1LL<<57LL
#define MAX 1000000
#define PI 3.14159265358979
#define ESP (1e-9)
 
//looping
#define fr(i,a) for(int i=0;i<a;i++)
#define fe(i,a) for(int i=0;i<=a;i++)
#define fu(i,a,n) for(int i=a;i<n;i++)
#define fue(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>a;i--)
#define fde(i,n,a) for(int i=n;i>=a;i--)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
 
//input output
#define sd(n) scanf("%d",&n)
#define sld(n) scanf("%ld",&n)
#define slld(n) scanf("%lld",&n)
#define pfd(n) printf("%d",n)
#define pfld(n) printf("%ld",n)
#define pflld(n) printf("%lld",n)
 
#define ff first
#define ss second
#define sz size()
#define clr clear()
// #define len length()
#define pb push_back
#define mp make_pair
#define gcd(a,b)  __gcd(a,b)
#define all(vi) vi.begin(), vi.end()
#define mem(i,n) memset(i,n,sizeof(i))
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
 
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define ldmax numeric_limits<ld>::max()
#define ldmin numeric_limits<ld>::min()
#define lldmax numeric_limits<lld>::max()
#define lldmin numeric_limits<lld>::min()
//end of definition
  
//fast output
 
//no line break
void print_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
 
//new line
void println_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
 
//special char
char sp;
void printsp_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
#define N 100010 
//end of fast output

bool vis[N],st[N],en[N];
vi edg[N],res;

void bfs(int x,int len,bool eflip,bool oflip){
	vis[x]=true;
	if(len%2==0 && eflip==0 && st[x]!=en[x]) res.pb(x),eflip=!eflip;
	else if(len%2==0 && eflip==1 && st[x]==en[x]) res.pb(x),eflip=!eflip;
	else if(len%2==1 && oflip==0 && st[x]!=en[x]) res.pb(x),oflip=!oflip;
	else if(len%2==1 && oflip==1 && st[x]==en[x]) res.pb(x),oflip=!oflip;
	fr(i,edg[x].size()){
		if(!vis[edg[x][i]]) bfs(edg[x][i],len+1,eflip,oflip);
	}
}

int main()
{
	IOS;
	int n,a,b;cin >> n;
	fr(i,n-1) {cin >> a >> b;edg[a].pb(b);edg[b].pb(a);}
	fr(i,n) cin >> st[i+1];
	fr(i,n) cin >> en[i+1];
	bfs(1,0,0,0);
	cout << res.size() << endl;
	fr(i,res.size()) cout << res[i] << '\n';
}