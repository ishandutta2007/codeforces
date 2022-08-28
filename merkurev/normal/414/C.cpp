#include <iostream>
#include <algorithm>
using namespace std;



const int maxn = (1 << 20) + 100;

int a[maxn], b[maxn];

long long numInv[21];
long long numAntiInv[21];



int fn[maxn];

int getSumP(int x)
{
	int ans = 0;
	for (; x > 0; x = (x & (x - 1) ) )
		ans += fn[x];
	return ans;		
}

void addEl(int x, int val)
{
	for (; x < maxn; x = (x | (x - 1) ) + 1)
		fn[x] += val;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif                                       

	int n;
	scanf("%d", &n);
	int N = (1 << n);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i] );
		b[i] = a[i];
	}
	sort(b, b + N);
	int M = unique(b, b + N) - b;
	for (int i = 0; i < N; i++)
		a[i] = lower_bound(b, b + M, a[i] ) - b + 5;
                 
	for (int st = 0; st < n; st++)
	{
		int cnt = (1 << st);
		int size = (N >> st);
		int hs = (size >> 1);

//		fprintf(stderr, "st = %d, cnt = %d, size = %d, hs = %d\n", st, cnt, size, hs);

		int lb = 0;
		for (int i = 0; i < cnt; i++)
		{
//			fprintf(stderr, "i = %d\n", i);
			long long curinv = 0;
			long long curainv = 0;
			for (int j = lb; j < lb + hs; j++)
			{
		//		fprintf(stderr, "j = %d, a[j] = \n%d", j, a[j] );
				addEl(a[j], 1);
			}
			for (int j = lb + hs; j < lb + size; j++)
			{
				int lseq = getSumP(a[j] );
			        int ls = getSumP(a[j] - 1);
				int gr = hs - lseq;
				curinv += gr;
				curainv += ls;
//				printf("j = %d, lseq = %d, ls = %d, gr = %d\n", j, lseq, ls, gr);	
			}
			for (int j = lb; j < lb + hs; j++)	
				addEl(a[j], -1);
			
			numInv[st] += curinv;
			numAntiInv[st] += curainv;
                                                  
			lb += size;
		}
	}       
//	return 0;  

//	for (int i = 0; i <= n; i++)
//		fprintf(stderr, "%d: %I64d %I64d\n", i, numInv[i], numAntiInv[i] );

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		long long ans = 0;
		for (int i = n - x; i < n; i++)
		{
			swap(numInv[i], numAntiInv[i] );	
		}
		for (int i = 0; i < n; i++)
			ans += numInv[i];
		printf("%I64d\n", ans);
	}


	return 0;
}