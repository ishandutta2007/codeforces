#include <bits/stdc++.h>
using namespace std;
struct node
{
	node *lasti, *nexti;
	string s;
}*qwq, *st;
map<string, node *> m;
int n;
string S;
int main()
{
	scanf("%d", &n);
	st = NULL;
	for (int i = 1; i <= n; i++)
	{
		cin >> S;
		if (m.count(S))
		{
			qwq = m[S];
			if (qwq != st)
			{
				if (qwq->lasti != NULL) qwq->lasti->nexti = qwq->nexti;
				if (qwq->nexti != NULL) qwq->nexti->lasti = qwq->lasti;
				st->lasti = qwq;
				qwq->nexti = st;
				qwq->lasti = NULL;
				st = qwq;
			}
		}
		else
		{
			qwq = new node;
			qwq->s = S;
			m[S] = qwq;
			qwq->nexti = st;
			qwq->lasti = NULL;
			if (st != NULL) st->lasti = qwq;
			st = qwq;
		}
	}
	for (node *x = st; x != NULL; x = x->nexti) cout << x->s << endl;
	return 0;
}