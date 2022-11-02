#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct widget
{
	int h,w;
	widget(int x,int y)
	{
		w=x;
		h=y;
	}
};

struct Box
{
	int bor,space;
	int cnt;
	ll sumh;
	ll sumw;
	ll maxh;
	ll maxw;
	char t;
	ll w,h;
	bool was;
	Box(char c)
	{
		was=false;
		bor=space=cnt=0;
		sumh=sumw=maxh=maxw=0;
		w=0;
		h=0;
		t=c;
	}
	multiset<string> inc;
};

struct res
{
	string name;
	ll w,h;
	res(string n,ll x,ll y)
	{
		name=n;
		w=x;
		h=y;
	}
};

bool operator<(res &a,res &b)
{
	return a.name<b.name;
}

map<string,widget *> mW;
map<string, Box*> mB;

void proces(Box *b)
{
	if (b->was) return;
	b->was=1;
	typedef multiset<string>::iterator it;
	b->cnt=b->maxh=b->maxw=b->sumh=b->sumw=0;
	widget *curr;
	Box * bx;
	for (it i=b->inc.begin();i!=b->inc.end();i++)
	{
		if (mB.find(*i)==mB.end())
		{
			curr=mW[*i];
			b->maxh=max(b->maxh,ll(curr->h));
			b->maxw=max(b->maxw,ll(curr->w));
			b->cnt++;
			b->sumh+=curr->h;
			b->sumw+=curr->w;
		}
		else
		{
			bx=mB[*i];
			proces(bx);
			b->maxh=max(b->maxh,bx->h);
			b->maxw=max(b->maxw,bx->w);
			b->cnt++;
			b->sumh+=bx->h;
			b->sumw+=bx->w;
		}
	}
	if (b->t=='V')
	{
		b->w=b->maxw;
		b->h=b->sumh;
		if (b->cnt>=1)
		{
			b->w+=2*b->bor;
			b->h+=2*b->bor + (b->cnt-1)*b->space;
		}
	}
	else
	{
		b->h=b->maxh;
		b->w=b->sumw;
		if (b->cnt>=1)
		{
			b->w+=2*b->bor + (b->cnt-1)*b->space;
			b->h+=2*b->bor;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	char str[1000],str2[1000],name[1000],sx[100],sy[100],arg[1000];
	rep(i,0,n)
	{
		scanf(" %s",str);
		string curr=str;
		int p=-1;
		for (int j=0;str[j];j++)
			if (str[j]=='.') 
			{
				p=j;
				break;
			}
		if (p==-1)
		{
			if (strcmp(str,"Widget")==0)
			{
				scanf(" %s",str2);
				for (int j=0;str2[j];j++)
					if (str2[j]==')' || str2[j]=='(' || str2[j]==',') str2[j]=' ';
				int x,y;
				sscanf(str2,"%s%d%d",name,&x,&y);
				mW[name]=new widget(x,y);
			}
			else
			{
				scanf(" %s",str2);
				mB[str2]=new Box(str[0]);
			}
		}
		else
		{
			strncpy(name,str,p);
			name[p]=0;
			for (int i=p;str[i];i++)
				if (str[i]=='(' || str[i]==')') str[i]=' ';
			sscanf(str+p+1," %s %s",str2,arg);
			if (strcmp(str2,"pack")==0)
			{
				mB[name]->inc.insert(arg);
			}
			else if (strcmp(str2,"set_border")==0)
			{
				mB[name]->bor=atoi(arg);
			}
			else 
				mB[name]->space=atoi(arg);
		}
	}
	vector<res> ans;
	for (map<string, Box*>::iterator i=mB.begin();i!=mB.end();i++)
	{
		proces(i->second);
		ans.push_back(res(i->first,i->second->w,i->second->h));
	}
	for (map<string, widget*>::iterator i=mW.begin();i!=mW.end();i++)
	{
		ans.push_back(res(i->first,i->second->w,i->second->h));
	}
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++)
		printf("%s %lld %lld\n",ans[i].name.c_str(),ans[i].w,ans[i].h);
	return 0;	
}
/*
12
Widget me(50,40)
VBox grandpa
HBox father
grandpa.pack(father)
father.pack(me)
grandpa.set_border(10)
grandpa.set_spacing(20)
Widget brother(30,60)
father.pack(brother)
Widget friend(20,60)
Widget uncle(100,20)
grandpa.pack(uncle)

5
Widget me(50,40)
VBox grandpa
HBox father
grandpa.pack(father)
father.pack(me)
grandpa.set_border(10)
grandpa.set_spacing(20)
Widget brother(30,60)
father.pack(brother)
Widget friend(20,60)
Widget uncle(100,20)
grandpa.pack(uncle)


7
Widget pack(10,10)
HBox dummy
HBox x
VBox y
y.pack(dummy)
y.set_border(5)
y.set_spacing(55)
*/