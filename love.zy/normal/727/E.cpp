#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

char s[1000005];
char ss[2000005];
int i,j,k,g,n,ans,t,m;
int num[2000005];
int hh[100005];

#define LETTER 26
struct Trie{
	int num, fail, match;
	int next[LETTER];
}trie[2200005];
int cnt;
void init(){
	cnt = 1;
	memset(trie, 0, 2 * sizeof(Trie));
	trie[0].fail = 1;
}
inline int convert(char ch){ return ch - 'a'; }
void insert(char *s,int bj)
{
	int cur = 0;
	for (int i = 0; s[i]; i++){
		int &pos = trie[cur].next[convert(s[i])];
		if (!pos){
			pos = ++cnt;
			memset(&trie[cnt], 0, sizeof(Trie));
		}
		cur = pos;
	}
	trie[cur].num=bj;
}
void makeFail()
{
	queue<int> q; q.push(0);
	while (!q.empty()){
		int t = q.front(); q.pop();
		for (int i = 0; i < LETTER; i++){
			int &cur = trie[t].next[i];
			if (cur){
				q.push(cur);
				trie[cur].fail = trie[trie[t].fail].next[i];
				trie[cur].match = trie[cur].num ? cur : trie[trie[cur].fail].match;
			}
			else cur = trie[trie[t].fail].next[i];
		}
	}
}
void search(char *s)
{
	int ret = 0, cur = 0;
	for (int i = 0; i < t ; i++){
		cur = trie[cur].next[convert(s[i])];
		for (int temp = trie[cur].match; temp; temp = trie[trie[temp].fail].match)
			//ret += trie[temp].num;
            num[i-k+1]=trie[temp].num;
	}
	//return ret;
}

int main()
{
    init();
    scanf("%d %d\n",&g,&k);
    gets(ss);
    t=strlen(ss);
	scanf("%d\n",&n);
    for(i=0;i<k;i++)ss[i+t]=ss[i];
    t+=k;ss[t]='\0';
	for(i=1;i<=n;i++)
	{
		gets(s);
		insert(s,i);
	}
    makeFail();
    search(ss);
    bool f=false;
    for(i=1;i<=n;i++)hh[i]=-1;
    for(i=0;i<k;i++)
    {
        f=true;
        for(j=1;j<=g;j++)
        {
            int pos=(j-1)*k+i;
            if(hh[num[pos]]==i || num[pos]==0){f=false;break;}
            if(hh[num[pos]]!=i)hh[num[pos]]=i;
        }
        if(f)
        {
            printf("YES\n");
            for(j=1;j<=g;j++)
            {
                if(j>1)printf(" ");
                printf("%d",num[(j-1)*k+i]);
            }
            return 0;
        }
    }
    printf("NO");
	return 0;
}