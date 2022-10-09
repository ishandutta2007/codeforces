    #include <bits/stdc++.h>
    using namespace std;
    #define e1 first
    #define e2 second
    #define pb push_back
    #define mp make_pair
    #define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
    #define eb emplace_back
    #define OUT(x) {cout << x; exit(0); }
    #define REYNA(i,a,b) for(int i=(a);i<(b);++i)
    #define FOR(i,a,b) for(int i=(a);i<=(b);++i)
    #define scanf(...) scanf(__VA_ARGS__)?:0
    typedef long long int ll;
    typedef unsigned long long ull;
    typedef pair <int, int> PII;
    typedef pair <ll, ll> PLL;
    typedef pair <PLL, int> PLLI;
    typedef pair <PLL, PLL > PP;
    typedef pair <PII, int> PPI;
    typedef pair <int, PII> PIP;
    typedef pair <ll, int> PLI;
    typedef unsigned int ui;
    const int mod = 1e9+7;
    const int inf = 1e9+9;
    const ll MOD = 1e9+696969;
    const long long INF = 1e18+3;
    const int maxn = 500100;
     
    int sp[19][maxn];
    int LOG[maxn], n, tab[maxn];
    int POS[maxn];
     
    inline int query(int x, int y)
    {
    	int LEN = y-x+1, ln = LOG[LEN];
    	return min(sp[ln][x], sp[ln][y-(1<<ln)+1]);
    }
     
    inline int solve(int X, int Y)
    {
    	if (X > Y) return 0;
    	if (X == Y) return 1;
    	int g = query(X, Y), poss = -1;
    	if (X <= POS[g] && POS[g] <= Y) poss = POS[g];
    	else poss = POS[g] + n;
    	
    	return 1 + max(solve(X, poss - 1), solve(poss + 1, Y));
    }
     
    inline int rollsolve(int X, int Y)
    {
    	if (X < 0) return solve(X + n, Y + n);
    	return solve(X, Y);
    }
     
    int main()
    {
    	FOR(j, 0, 18) LOG[1 << j] = j;
    	FOR(j, 1, maxn-1)
    		if (!LOG[j]) LOG[j] = LOG[j-1];
    	boost;
    	cin >> n;
    	FOR(i, 1, n) cin >> tab[i], tab[n + i] = tab[i], POS[tab[i]] = i;
    	/*FOR(i, 1, n) tab[i] = i;
    	random_shuffle(tab+1, tab+n+1);
    	FOR(i, 1, n) tab[n + i] = tab[i], POS[tab[i]] = i;
    	*/
    	int BEG = POS[1], END = POS[1] - 1 + n;
    	int N = 2 * n;
    	FOR(i, 1, N) sp[0][i] = tab[i];
    	FOR(j, 1, 18)
    		FOR(i, 1, N)
    			if (i + (1 << j) - 1 <= N) sp[j][i] = min(sp[j-1][i], sp[j-1][i+(1<<(j-1))]);
    	
    	int RESULT = n, shift = 0;
    	while (BEG <= END)
    	{
    		int sr = (BEG + END) / 2;
    		int pos_jed = POS[1] - sr;
    		while (pos_jed < 1) pos_jed += n;
    		while (pos_jed >= POS[1] + n) pos_jed -= n;
    		int LEFT = rollsolve(POS[1] - pos_jed + 1, POS[1] - 1);
    		int RIGHT = rollsolve(POS[1] + 1, POS[1] + (n - pos_jed));
    		
    		if (max(LEFT, RIGHT) + 1 < RESULT)
    		{
    			RESULT = max(LEFT, RIGHT) + 1;
    			shift = sr;
    		}
    		
    		if (BEG == END) break;
    		//cout << "1: " << LEFT << ' ' << RIGHT << endl;
    		if (LEFT > RIGHT) BEG = sr + 1;
    		else END = sr;
    	}
    	
    	BEG = POS[1], END = POS[1] - 1 + n;
    	while (BEG <= END)
    	{
    		int sr = (BEG + END) / 2;
    		int pos_jed = POS[1] - sr;
    		while (pos_jed < 1) pos_jed += n;
    		while (pos_jed >= POS[1] + n) pos_jed -= n;
    		int LEFT = rollsolve(POS[1] - pos_jed + 1, POS[1] - 1);
    		int RIGHT = rollsolve(POS[1] + 1, POS[1] + (n - pos_jed));
    		
    		if (max(LEFT, RIGHT) + 1 < RESULT)
    		{
    			RESULT = max(LEFT, RIGHT) + 1;
    			shift = sr;
    		}
    		//cout << LEFT << ' ' << RIGHT << endl;
    		if (BEG == END) break;
    		if (LEFT < RIGHT) BEG = sr + 1;
    		else END = sr;
    	}
    	
    	//FOR(i, 1, n) cout << solve(i, i + n - 1) << ' ';
    	//cout << endl;
    	if (shift >= n) shift -= n;
    	cout << RESULT << ' ' << shift;
    }