n=input()
dp={"polycarp":1}
ans=1
for i in xrange(n):
	s=map(str.lower,raw_input().split(" reposted "))
	dp[s[0]]=dp[s[1]]+1
	ans=max(ans,dp[s[0]])
print ans