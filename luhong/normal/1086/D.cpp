#include <cstdio>
#include <set>
#define MN 201000

std::set<int> SR, SP, SS;
int CR[MN], CP[MN], CS[MN];
char s[MN];
std::set<int>::iterator it;
int n, q; 

void add(int *c, int x, int v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
int query(int *c, int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

int solve()
{
	int sum = 0;
	if(SR.size())
	{
		if(!SP.size()) sum += SS.size();
		else
		{
			int s1 = *SP.begin();
			int s2 = *SR.begin();
			if(s2 < s1) sum += query(CS, s1) - query(CS, s2);
			
			it = SP.end(); --it; int e1 = *it;
			it = SR.end(); --it; int e2 = *it;
			if(e2 > e1) sum += query(CS, e2) - query(CS, e1); 
		}
	}//S
	
	if(SP.size())
	{
		if(!SS.size()) sum += SR.size();
		else
		{
			int s1 = *SS.begin();
			int s2 = *SP.begin();
			if(s2 < s1) sum += query(CR, s1) - query(CR, s2);
			
			it = SS.end(); --it; int e1 = *it;
			it = SP.end(); --it; int e2 = *it;
			if(e2 > e1) sum += query(CR, e2) - query(CR, e1); 
		}
	}//R
	
	if(SS.size())
	{
		if(!SR.size()) sum += SP.size();
		else
		{
			int s1 = *SR.begin();
			int s2 = *SS.begin();
			if(s2 < s1) sum += query(CP, s1) - query(CP, s2);
			
			it = SR.end(); --it; int e1 = *it;
			it = SS.end(); --it; int e2 = *it;
			if(e2 > e1) sum += query(CP, e2) - query(CP, e1); 
		}
	}//P
//	 
	return n - sum;
}

int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == 'R') SR.insert(i), add(CR, i, 1); 
		if(s[i] == 'P') SP.insert(i), add(CP, i, 1); 
		if(s[i] == 'S') SS.insert(i), add(CS, i, 1); 
	}
	
	printf("%d\n", solve());
	
	for(int i = 1; i <= q; i++)
	{
		int wz; char c[2];
		scanf("%d%s", &wz, c);
		if(s[wz] == 'R') SR.erase(wz), add(CR, wz, -1); 
		if(s[wz] == 'P') SP.erase(wz), add(CP, wz, -1); 
		if(s[wz] == 'S') SS.erase(wz), add(CS, wz, -1); 
		
		if(c[0] == 'R') SR.insert(wz), add(CR, wz, 1); 
		if(c[0] == 'P') SP.insert(wz), add(CP, wz, 1); 
		if(c[0] == 'S') SS.insert(wz), add(CS, wz, 1); 
		
		s[wz] = c[0];
		
		printf("%d\n", solve());
	
	}
	return 0;
}