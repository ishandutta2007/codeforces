/*
PROG: cf871b
LANG: C++
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
 
long long readi()
{
	long long input = 0;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	bool negative = false;
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = 10 * input + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	return input;
}
void printi(long long output)
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
string reads()
{
	string input = "";
	char c = ' ';
	while (c <= ' ')
	{
		c = getchar();
	}
	while (c > ' ')
	{
		input += c;
		c = getchar();
	}
	return input;
}
void prints(string output)
{
	for (int i = 0; i < output.length(); i++)
	{
		putchar(output[i]);
	}
	return;
}

#define MP make_pair
#define PB push_back
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound
 
#define SINF 10007
#define MOD 1000000007
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 5010
 
typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int val[MAXN], pos[MAXN];
int tval[MAXN], tpos[MAXN];
int can[MAXN];
int ans;

int query(int x, int y)
{
	int input;
	cout << "? " << x << ' ' << y << '\n';
	fflush(stdout);
	cin >> input;
	if (input == -1)
	{
		exit(0);
	}
	return input;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
//	if (fopen("cf871b.in", "r"))
//	{	
//		freopen ("cf871b.in", "r", stdin);
//		freopen ("cf871b.out", "w", stdout);
//	}
	cin >> N;
	//using queries of the form p[i] xor b[0], we get val[i] xor val[j]
	//we also get pos[i] xor pos[j]
	for (int i = 0; i < N; i++)
	{
		val[i] = query(i, 0);
	}
	for (int i = 0; i < N; i++)
	{
		pos[i] = query(0, i);
	}
	for (int i = 0; i < N; i++)
	{
		//try setting i as the first #
		bool flag = true;
		for (int j = 0; j < N; j++)
		{
			//tpos[0] xor tval[j] == val[j], so tval[j] = pos[0] xor val[j]
			tval[j] = (i xor val[j]);
			if (tval[j] >= N)
			{
				flag = false;
			}
//			cerr << tval[j] << ' ';
		}
//		cerr << endl;
		if (!flag)
		{
			continue;
		}
		for (int j = 0; j < N; j++)
		{
			tpos[tval[j]] = j;
 		}
		//now check if it works
		for (int j = 0; j < N; j++)
		{
			if ((tpos[0] xor tval[j]) != val[j])
			{
				flag = false;
			}
			if ((tpos[j] xor tval[0]) != pos[j])
			{
				flag = false;
			}
		}
		if (!flag)
		{
			continue;
		}
		if (flag)
		{
			ans++;
			for (int j = 0; j < N; j++)
			{
				can[j] = tval[j];
//				cerr << can[j] << ' ';
			}
//			cerr << endl;
		}
	}
	cout << "! " << ans << '\n' << can[0];
	for (int i = 1; i < N; i++)
	{
		cout << ' ' << can[i];
	}
	cout << '\n';
	return 0;
}