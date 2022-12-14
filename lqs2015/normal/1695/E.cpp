#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int n, x[333333], y[333333], dfn[666666], cnt, low[666666], ed, num[666666], p[11], a[11];
bool can[5];
vector<int> g[666666];
vector<pair<int, int> > ans;
vector<pair<char, char> > ans1, ans2;
int lst[666666];
vector<vector<pair<int, int> > > v;
vector<pair<int, int > > fk;
void dfs(int i, int fa)
{
	dfn[i] = ++cnt;
    lst[i] = -1;
    vector<int> tos; tos.clear();
    for (int j = 0; j < g[i].size(); j++)
    {
        int to = g[i][j];
        if (to == fa) continue;
        if (!dfn[to])
        {
            dfs(to, i);
            if (lst[to] != -1)
            {
                fk.clear(); fk.push_back(make_pair(to, i));
                fk.push_back(make_pair(to, lst[to]));
                v.push_back(fk);
            }
            else tos.push_back(to);
        }
        else if (dfn[to] >= dfn[i])
        {
            tos.push_back(to);
        }
    }
    for (int j = 0; j < (int)tos.size() - 1; j += 2)
    {
        fk.clear(); fk.push_back(make_pair(i, tos[j]));
        fk.push_back(make_pair(i, tos[j + 1]));
        v.push_back(fk);
    }
    if ((int)tos.size() & 1)
    {
        lst[i] = tos.back();
        if (!fa) 
        {
            if (v.empty()) ed = 0;
            else 
            {
                for (int j = 0; j < v.size(); j++)
                {
                    bool f = 0;
                    for (int k = 0; k < v[j].size(); k++)
                    {
                        if (v[j][k].first == lst[i] || v[j][k].second == lst[i] || v[j][k].first == i || v[j][k].second == i)
                        {
                            f = 1;
                            break;
                        }
                    }
                    if (f) 
                    {
                        v[j].push_back(make_pair(i, lst[i]));
                        break;
                    }
                }
            }
        }
    }
}
void chk(vector<pair<int, int> > &v)
{
    assert((int)v.size() == 2 || (int)v.size() == 3);
    if (v.size() == 2)
    {
        assert(v[0].first == v[1].first);
        //cout << v[0].first << " " << v[0].second << " " << v[1].first << " " << v[1].second << endl;
        ans.push_back(make_pair(v[0].first, v[0].second));
        ans.push_back(make_pair(v[1].second, v[1].first));
        ans1.push_back(make_pair('L', 'L'));
        ans1.push_back(make_pair('R', 'R'));
        ans2.push_back(make_pair('U', 'D'));
        ans2.push_back(make_pair('U', 'D'));
    }
    else 
    {
        for (int i = 1; i <= 6; i++) p[i] = i;
        for (int i = 0; i < 3; i++)
        {
            a[i * 2 + 1] = v[i].first;
            a[i * 2 + 2] = v[i].second;
		}
        do
        {
            can[0] = can[1] = can[2] = 0;
            for (int i = 0; i < 3; i++)
            {
            	if (can[i]) continue;
            	if ((v[i].first == a[p[1]] && v[i].second == a[p[2]]) || (v[i].first == a[p[2]] && v[i].second == a[p[1]]))
            	{
            		can[i] = 1;
            		break;
				}
			}
			for (int i = 0; i < 3; i++)
            {
            	if (can[i]) continue;
            	if ((v[i].first == a[p[4]] && v[i].second == a[p[5]]) || (v[i].first == a[p[5]] && v[i].second == a[p[4]]))
            	{
            		can[i] = 1;
            		break;
				}
			}
			for (int i = 0; i < 3; i++)
            {
            	if (can[i]) continue;
            	if ((v[i].first == a[p[3]] && v[i].second == a[p[6]]) || (v[i].first == a[p[6]] && v[i].second == a[p[3]]))
            	{
            		can[i] = 1;
            		break;
				}
			}
			if (!can[0] || !can[1] || !can[2]) continue;
			can[0] = can[1] = can[2] = 0;
			for (int i = 0; i < 3; i++)
            {
            	if (can[i]) continue;
            	if ((v[i].first == a[p[1]] && v[i].second == a[p[4]]) || (v[i].first == a[p[4]] && v[i].second == a[p[1]]))
            	{
            		can[i] = 1;
            		break;
				}
			}
			for (int i = 0; i < 3; i++)
            {
            	if (can[i]) continue;
            	if ((v[i].first == a[p[2]] && v[i].second == a[p[3]]) || (v[i].first == a[p[3]] && v[i].second == a[p[2]]))
            	{
            		can[i] = 1;
            		break;
				}
			}
			for (int i = 0; i < 3; i++)
            {
            	if (can[i]) continue;
            	if ((v[i].first == a[p[5]] && v[i].second == a[p[6]]) || (v[i].first == a[p[6]] && v[i].second == a[p[5]]))
            	{
            		can[i] = 1;
            		break;
				}
			}
			if (can[0] & can[1] & can[2]) break;
 		}while(next_permutation(p + 1, p + 7));
 		ans.push_back(make_pair(a[p[1]], a[p[4]]));
 		ans.push_back(make_pair(a[p[2]], a[p[5]]));
 		ans.push_back(make_pair(a[p[3]], a[p[6]]));
        ans1.push_back(make_pair('U', 'D'));
        ans1.push_back(make_pair('L', 'L'));
        ans1.push_back(make_pair('R', 'R'));
        ans2.push_back(make_pair('L', 'L'));
        ans2.push_back(make_pair('R', 'R'));
        ans2.push_back(make_pair('U', 'D'));
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &x[i], &y[i]);
        g[x[i]].push_back(y[i]);
        if (x[i] != y[i]) g[y[i]].push_back(x[i]);
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!dfn[i]) 
        {
            ed = 1; v.clear();
            dfs(i, 0);
            if (ed == 0)
            {
                printf("-1\n");
                return 0;
            }
            for (int j = 0; j < v.size(); j++)
            {
            	/*for (int k = 0; k < v[j].size(); k++)
            	{
            		cout << v[j][k].first << " " << v[j][k].second << " "; 
				}
				cout << endl;*/
                chk(v[j]);
            }
        }
    }
    printf("2 %d\n\n", n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i - 1].first);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i - 1].second);
    }
    printf("\n\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%c", ans1[i - 1].first);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%c", ans1[i - 1].second);
    }
    printf("\n\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%c", ans2[i - 1].first);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%c", ans2[i - 1].second);
    }
    printf("\n\n");
	return Accepted;
}