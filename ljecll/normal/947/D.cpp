/*
PROG: cf947d
LANG: C++11
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
 */
#include <bits/stdc++.h>

using namespace std;

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-20;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 100013

template<class T>
T normalize(T x, T mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string inputs;
bool was[MAXN], want[MAXN];
int pwas[MAXN], pwant[MAXN];
int awas[MAXN], awant[MAXN];
int N, M, Q;
string ans;

bool solve(int L1, int R1, int L2, int R2)
{
	//	cerr << L1 << ' ' << R1 << ' ' << L2 << ' ' << R2 << endl;
	if (L1 > R1)
	{
		assert(L1 - R1 == 1);
		return (L2 - R2 == 1);
	}
	int nbwas, nbwant, bawas, bawant;
	bawas = min(R1 - L1 + 1, awas[R1 + 1]);
	bawant = min(R2 - L2 + 1, awant[R2 + 1]);
	//		cerr << bawas << ' ' << bawant << endl;
	if (bawant > bawas)
	{
		return 0;
	}
	nbwas = pwas[R1 + 1] - pwas[L1];
	nbwant = pwant[R2 + 1] - pwant[L2];
	if ((nbwant + nbwas) % 2)
	{
		return 0;
	}
	//bawant <= bawas
	if (bawant)
	{
		return solve(L1, R1 - bawant, L2, R2 - bawant);
	}
	bawas %= 3;
	//all these A's must turn into BB
	if (bawas)
	{
		if (nbwant < 2 + nbwas)
		{
			return 0;
		}
	}
	else
	{
		if (nbwant < nbwas)
		{
			return 0;
		}
	}
	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf947d.in", "r"))
	{	
		freopen ("cf947d.in", "r", stdin);
		freopen ("cf947d.out", "w", stdout);
	}
	cin >> inputs;
	M = inputs.length();
	for (int i = 0; i < M; i++)
	{
		was[i] = (inputs[i] - 'A');
		pwas[i + 1] = pwas[i] + was[i];
		if (!was[i])
		{
			awas[i + 1] = awas[i] + 1;
		}
		else
		{
			awas[i + 1] = 0;
		}
	}
	cin >> inputs;
	N = inputs.length();
	for (int i = 0; i < N; i++)
	{
		want[i] = (inputs[i] - 'A');
		pwant[i + 1] = pwant[i] + want[i];
		if (!want[i])
		{
			awant[i + 1] = awant[i] + 1;
		}
		else
		{
			awant[i + 1] = 0;
		}
	}
	//LOL WTF B=C
	//A -> BB, B -> AB, AAA -> nothing
	//so the # of B is constant mod 2
	//how do you check if you can change one string to another?
	cin >> Q;
	while(Q--)
	{
		int L1, R1, L2, R2;
		cin >> L1 >> R1 >> L2 >> R2;
		L1--; R1--; L2--; R2--;
		cout << solve(L1, R1, L2, R2);
		//use L1, R1 in was to make L2, R2 in want
		//you can get rid of any A's that appear before a B
		//so the final condition is:
		//# of B's mod 2 is same
		//the size of ending block of A's is strictly equal iff # bs are equal
	}
	cout << '\n';
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}