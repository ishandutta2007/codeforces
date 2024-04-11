# include <iostream>
# include <cstring>
# include <cstdio>
using namespace std;

int nb, ns, nc, pb, ps, pc, sb, ss, sc, n;
long long c;
bool calc(long long n) {
	long long t = 0;
	t += max(1LL * pb * (n * sb - nb), 0LL);
	t += max(1LL * ps * (n * ss - ns), 0LL);
	t += max(1LL * pc * (n * sc - nc), 0LL);
	return (t <= c);
}

int main() {
	char a[200]; scanf("%s", a);
	for(int i=0; i<strlen(a); i++) 
		switch(a[i]) {
			case 'B': sb++; break;
			case 'S': ss++; break;
			case 'C': sc++; break;
		}

	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> c;
	if(sb==0)sb=1, pb=0;
	if(ss==0)ss=1, ps=0;
	if(sc==0)sc=1, pc=0;
	
	long long L = 0, R = c+nb+ns+nc+1, Mid;
	while(R-L>1) 
		calc(Mid=(L+R)>>1)?L=Mid:R=Mid;

	cout<<L<<endl;
}