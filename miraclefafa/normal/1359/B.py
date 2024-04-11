t=int(input())

def solve(s):
	f=len(s)
	dp=[0]*(f+1)
	for i in range(f):
		if s[i]=='.':
			dp[i+1]=dp[i]+x
			if i>=1 and s[i-1]=='.':
				dp[i+1]=min(dp[i+1],dp[i-1]+y)
		else:
			dp[i+1]=dp[i]
	return dp[f]

for i in range(t):
	n,m,x,y=map(int,input().split())
	ans=0;
	for j in range(n):
		ans+=solve(input())
	print(ans)