#include <bits/stdc++.h>

using namespace std;

#define DB(x) cerr<< __LINE__ << " : " << #x << " = " << (x) << endl;
#define foreach(it,c) for(__typepf((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define MP make_pair

typedef long long i64;
typedef pair<int,int> pii;

void tolower(string &s)
{
    for(int i = 0; i < s.length(); ++i)
        s[i] = tolower(s[i]);
}

const int N = (int)1e6 + 100;

struct node
{
    int r, len, id;

    bool operator<(const node &n) const
    {
        if(r != n.r) return r > n.r;

        return len > n.len;
    }
};

map<string,node> M;
vector<int> G[N];

string words[N];
string ids[N];

bool mark[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;

    cin >> m;

    for(int i = 0; i < m; ++i)
    {
        cin >> words[i];
        tolower(words[i]);
    }

    int n;

    cin >> n;

    priority_queue<node> PQ;

    for(int i = 0; i < n; ++i)
    {
        string s;

        cin >> s;
        tolower(s);

        node nod = (node){count(s.begin(),s.end(),'r'),s.length(),M.size()+1};

        if(M.insert(MP(s,nod)).second) PQ.push(nod), ids[nod.id] = s;

        int id1 = M[s].id;

        cin >> s;
        tolower(s);

        nod = (node){count(s.begin(),s.end(),'r'),s.length(),M.size()+1};

        if(M.insert(MP(s,nod)).second) PQ.push(nod), ids[nod.id] = s;

        int id2 = M[s].id;

        G[id2].push_back(id1);
    }

    while(!PQ.empty())
    {
        node nod = PQ.top(); PQ.pop();

        mark[nod.id] = true;

        for(int i = G[nod.id].size() - 1; i > -1; --i)
        {
            int next = G[nod.id][i];

            if(!mark[next])
            {
                M[ids[next]].r = nod.r;
                M[ids[next]].len = nod.len;

                PQ.push(M[ids[next]]);

                mark[next] = true;
            }
        }
    }

    i64 r = 0, len = 0;

    for(int i = 0; i < m; ++i)
    {
        if(!M.count(words[i])) r += count(words[i].begin(),words[i].end(),'r'), len += words[i].length();
        else r += M[words[i]].r, len += M[words[i]].len;
    }

    cout << r << " " << len << endl;

    return 0;
}