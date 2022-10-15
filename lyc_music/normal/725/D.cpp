//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define WCR_AKIOI 1
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int n,l;
long long rk;
priority_queue<int> q;
struct node
{
	int w,t;
}a[300005];

bool Cmp(node x,node y)
{
	return x.t<y.t;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i].t=read(),a[i].w=read();
	sort(a+2,a+n+1,Cmp);
	l=n;rk=INT_MAX;
	while (WCR_AKIOI)
	{
		while (l>=1&&a[l].t>a[1].t) q.push(-(a[l].w-a[l].t+1)),l--;
		rk=min(rk,(long long)q.size()+1);
//		cout<<rk<<" "<<q.size()<<" "<<a[1].t<<endl;
		if (q.size())
		if (a[1].t>=(-q.top()))
		{
			a[1].t-=-q.top();
			q.pop();
		} else break; else break;
	}
	writeln(rk);
}