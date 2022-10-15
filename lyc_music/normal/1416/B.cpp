//QwQcOrZ yyds!!!
#include<bits/stdc++.h>

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

int T,n,bl,sum,a[100005];
vector<pair<int,pair<int ,int > > >ans;

signed main()
{
	T=read();
	while (T--)
	{
		n=read();bl=0;sum=0;ans.clear();
		for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
		if (sum%n!=0)
		{
			printf("-1\n");
			continue;
		}
		sum/=n;
		for (int i=2;i<=n;i++)
			if (a[i]%i==0)
				ans.push_back(make_pair(i,make_pair(1,a[i]/i))),a[i]=0,a[1]+=a[i];
		for (int i=2;i<=n;i++)
		  	if (a[i]%i!=0)
		  	{
		  		ans.push_back(make_pair(1,make_pair(i,i-(a[i]%i))));
		  		a[i]+=i-(a[i]%i);
		  		a[1]-=i-(a[i]%i);
		  		ans.push_back(make_pair(i,make_pair(1,a[i]/i)));
		  		a[i]=0,a[1]+=a[i];
		  	}
		for (int i=2;i<=n;i++) 
		  	ans.push_back(make_pair(1,make_pair(i,sum)));
		writeln(ans.size());
		for (int i=0;i<ans.size();i++) 
		writesp(ans[i].first),writesp(ans[i].second.first),writeln(ans[i].second.second);
	}
}