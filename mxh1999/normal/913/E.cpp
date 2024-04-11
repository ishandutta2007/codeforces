#include<bits/stdc++.h>
using namespace std;

string f[256][3];
bool vis[256][3];
char s[10];

pair<int,int> que[1010];
inline void update(string& s1,string s)
{
	if (s1.length()==0 || s1.length()>s.length())	s1=s;
	if (s1.length()==s.length() && s1>s)	s1=s;
}
void prepare()
{
	f[15][0]=f[15][1]=f[15][2]="x";
	f[51][0]=f[51][1]=f[51][2]="y";
	f[85][0]=f[85][1]=f[85][2]="z";
	int cnt=0;
	for (int te=1;te<=768;te++)
	{
		pair<int,int> ha=make_pair(-1,-1);
		for (int i=0;i<256;i++)
			for (int j=0;j<3;j++)
			if (!vis[i][j] && f[i][j].length()>0)
			{
				if (ha.first==-1 || f[i][j].length()<f[ha.first][ha.second].length())
				{
					ha=make_pair(i,j);
				}
			}
		if (ha.first==-1)	break;
		que[++cnt]=ha;
		vis[ha.first][ha.second]=true;
		if (ha.second<=0)
		{
			update(f[ha.first^255][0],'!'+f[ha.first][ha.second]);
		}	else
		{
			update(f[ha.first^255][0],"!("+f[ha.first][ha.second]+')');
		}
		for (int i=1;i<cnt;i++)
		{
			string tmp;
			if (que[i].second<=1)	tmp=f[que[i].first][que[i].second];else tmp='('+f[que[i].first][que[i].second]+')';
			if (ha.second<=1)	update(f[que[i].first&ha.first][1],tmp+'&'+f[ha.first][ha.second]),update(f[que[i].first&ha.first][1],f[ha.first][ha.second]+'&'+tmp);
				else update(f[que[i].first&ha.first][1],tmp+"&("+f[ha.first][ha.second]+')'),update(f[que[i].first&ha.first][1],"("+f[ha.first][ha.second]+")&"+tmp);
			update(f[que[i].first|ha.first][2],f[que[i].first][que[i].second]+'|'+f[ha.first][ha.second]);
			update(f[que[i].first|ha.first][2],f[ha.first][ha.second]+'|'+f[que[i].first][que[i].second]);
		}
	}
}
void outit(int num)
{
	string tmp;
	for (int i=0;i<3;i++)
		if (f[num][i].length()!=0)
		{
			update(tmp,f[num][i]);
		}
	cout<<tmp<<endl;
}
int main()
{
	prepare();
	int te;
	scanf("%d",&te);
	while (te--)
	{
		scanf("%s",s+1);
		int num=0;
		for (int i=1;i<=8;i++)
			num=num*2+s[i]-'0';
		outit(num);
	}
	return 0;
}