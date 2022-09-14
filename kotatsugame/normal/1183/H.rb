N,k=gets.split.map &:to_i
s=gets.chomp
dp=(0..100).map{[0]*101}
dp[0][0]=1
N.times{|i|
	(1..i+1).each{|j|
		0.upto(i){|k|dp[i+1][j]+=dp[k][j-1]}
		i.times{|k|dp[i+1][j]-=dp[k+1][j] if s[i]==s[k]}
	}
}
SUM=(0..N).map{|i|t=0;(0..N).each{|j|t+=dp[j][i]};t}
ans=0
N.downto(0){|i|
	t=[SUM[i],k].min
	k-=t
	ans+=t*(N-i)
}
p k>0 ? -1 : ans