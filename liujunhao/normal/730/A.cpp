#include<cstdio>
#include<algorithm>
#include<set>
#include<string>
#include<iostream>
#define MAXN 100
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int n,a[MAXN+10],cnt;
string d,b;
struct node{
	int a,b,c;
	inline node(){
	}
	inline node(int a,int b,int c=0):a(a),b(b),c(c){
	}
}ans[10010];
typedef pair<int,int>pii;
multiset<pii,greater<pii> >s;
int main()
{
	Read(n);
	int i;
	for(i=1;i<=n;i++){
		Read(a[i]);
		s.insert(pii(a[i],i));
	}
	if(n==2){
		if(a[1]==a[2])
			printf("%d\n%d\n",a[1],0);
		else{printf("%d\n%d\n",0,max(a[1],a[2])); for(int i=max(a[1],a[2]);i;i--)
			puts("11");
		}
		return 0;
	}
	while(s.begin()->first!=s.rbegin()->first){
		auto l=s.begin();
		auto j=l++;
		pii a=*j,b=*l;
		s.erase(j),s.erase(l);
		a.first=max(a.first-1,0),b.first=max(b.first-1,0);
		auto k=s.begin();
		if(k->first==a.first+1){
			pii c=*k;
			s.erase(k);
			if(s.empty()||(s.begin()->first==a.first&&s.rbegin()->first==a.first)){
				ans[++cnt]=node(a.second,b.second,c.second);
				break;
			}
			s.insert(c);
		}
		ans[++cnt]=node(a.second,b.second);
		s.insert(a),s.insert(b);
	}
	printf("%d\n%d\n",s.begin()->first,cnt);
	for(i=0;i<n;i++)
		d+='0';
	for(i=1;i<=cnt;i++){
		b=d;
		b[ans[i].a-1]='1',b[ans[i].b-1]='1';
		if(ans[i].c)
			b[ans[i].c-1]='1';
		cout<<b<<endl;
	}
}