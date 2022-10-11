#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
bool vis[1005][15][15][2];
struct state {
	int a,b,c,add;
};
state make_state(int aa,int bb,int cc,int addd)
{
	state tmp;
	tmp.a=aa;
	tmp.b=bb;
	tmp.c=cc;
	tmp.add=addd;
	return tmp;
}
state par[1005][15][15][2];
void go(state st)
{
	if (!st.b)
	return;
	go(par[st.a][st.b][st.add][st.c]);
	cout << st.add << ' ';
}
int main()
{
	string s;
	int n;
	cin >> s >> n;
	queue<state> q;
	q.push(make_state(0,0,1,0));
	while (!q.empty())
	{
		state st=q.front();
		q.pop();
		if (st.a==n)
		{
			cout << "YES\n";
			go(st);
			return 0;
		}
		for (int i=0;i<10;i++)
		{
			if (s[i]=='1')
			{
				state tmp=st;
				tmp.a++;
				tmp.b-=i+1;
				tmp.c^=1;
				tmp.add=i+1;
				if (tmp.b>=10 || st.add==i+1 || tmp.b>=0)
				continue;
				tmp.b=abs(tmp.b);
				if (!vis[tmp.a][tmp.b][tmp.add][tmp.c])
				{
					q.push(tmp);
					vis[tmp.a][tmp.b][tmp.add][tmp.c]=1;
					par[tmp.a][tmp.b][tmp.add][tmp.c]=st;
				}
			}
		}
	}
	cout << "NO";
}