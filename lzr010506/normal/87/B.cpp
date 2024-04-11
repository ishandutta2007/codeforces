#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define FOR(i, x, y) for(int (i) = (x); (i) < (y); (i) ++)
using namespace std;
char s[1000];
string ss;
map<string, pii > Map;

int main()
{
	int i,j,n,ty,cnt;
	Map.clear();
	Map["void"] = mp(1,0);
	scanf("%d",&n);
	FOR(i, 0, n)
	{
		scanf("%s", s);
		ss = s;
		if (ss == "typedef")
		{
			scanf("%s", s);
			ss = s;
			cnt = 0;
			while ((ss.length() > 0) && (ss[0] == '&'))
			{
				cnt --;
				ss = ss.substr(1);
			}
			while ((ss.length() > 0) && (ss[ss.length() - 1] == '*'))
			{
				cnt++;
				ss = ss.substr(0, ss.length() - 1);
			}
			if (Map.find(ss) == Map.end()) ty = 0;
			else
			{
				ty = Map[ss].first;
				cnt += Map[ss].second;
			}
			if (ty == 0) cnt = 0;
			else if (cnt < 0) ty = 0, cnt = 0;
			scanf("%s",s);
			ss = s;
			Map[ss] = mp(ty,cnt);
		}
		else
		{
			scanf("%s",s);
			ss=s;
			cnt=0;
			while ((ss.length()>0)&&(ss[0]=='&'))
			{
				cnt--;
				ss=ss.substr(1);
			}
			while ((ss.length()>0)&&(ss[ss.length()-1]=='*'))
			{
				cnt++;
				ss=ss.substr(0,ss.length()-1);
			}
			if (Map.find(ss)==Map.end())
			{
				printf("errtype\n");
			}
			else
			{
				if (Map[ss].first==0) printf("errtype\n");
				else
				{
					cnt+=Map[ss].second;
					if (cnt<0) printf("errtype\n");
					else
					{
						printf("void");
						for (j=0;j<cnt;j++)
							printf("*");
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}