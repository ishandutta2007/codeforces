#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

/*

aacbaaaca


*/



int solve()
{
    string s;
    cin >> s;
    n = s.size();

    vvi pil(n+15, vi(30, -1));
    pil[0][s[0]-'a'] = 0;

    //vector<int> pi (n, 0);
	for (int i = 1; i < n; ++i)
    {
		int j = pil[i-1][s[i]-'a'];
		pil[i][s[j+1]-'a'] = j+1;

		/*if (i == 5)
        {
            log(j);
            log(i);
            log(pil[j+1]);
            cendl;
        }*/

		if (j != -1)
        {
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c == s[j+1])
                    continue;

                pil[i][c-'a'] = pil[j][c-'a'];
            }
        }

		/*while (j > 0 && s[i] != s[j])
			j = pi[j-1];

		if (s[i] == s[j])
            ++j;

		pi[i] = j;*/
	}
	/*for (int i = 0; i < s.size(); ++i)
        {
            cout << i << ":  " << pil[i]<<endl;
        }*/

	int q;
	cin >> q;

	for (int id = 0; id < q; ++id)
	{
	    string nt;
	    cin >> nt;
	    for (int i = 0; i < nt.size(); ++i)
	    {
            for (int j = 0; j < pil[n+i].size(); ++j)
            {
                pil[n+i][j] = -1;
            }
	    }


	    for (int i = 0; i < nt.size(); ++i)
        {
            int ii = i+n;

            int j = pil[ii-1][nt[i]-'a'];

            char cr;
            if (j+1 < n)
                cr = s[j+1];
            else
                cr = nt[j+1-n];
            pil[ii][cr-'a'] = j+1;
            cout << j+1 << ' ';

            if (j != -1)
            {
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (c == cr)
                        continue;

                    pil[ii][c-'a'] = pil[j][c-'a'];
                }
            }

        }
	    cendl;

        /*for (int i = 0; i < s.size()+nt.size(); ++i)
        {
            log(pil[i]);
        }*/

	}

	/*for (int i = 0; i < pil.size(); ++i)
	{
	    log(pil[i]);
	}*/



    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}