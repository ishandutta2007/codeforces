n=gets.to_i
d=[]
n.times{|i| 
	d[i]=gets.split(' ')
	n.times{|j| d[i][j]=d[i][j].to_i}
}
n.times{|k|
	n.times{|i|
		n.times{|j| d[i][j] = [d[i][j], d[i][k] + d[k][j]].min}
	}
}
ans=0
n.times{|i|
	n.times{|j| ans=[ans, d[i][j]].max}
}
p ans