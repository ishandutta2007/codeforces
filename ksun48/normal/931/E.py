s=input()

d=dict()
mod=[]
mx=[]

for k in s:
	d[k]=[]
for i in range(len(s)):
	d[s[i]].append(i)
index=0
for k in d.keys():
	mod.append(d[k])

for k in mod:
	mxct=0
	ct=0
	x=[]
	for i in range(len(s)):
		ct=0
		dic=dict()
		for j in k:
			elt = s[(j+i)%(len(s))]
			if elt in dic.keys():
				dic[elt]+=1
			else:
				dic[elt]=1
		for r in dic.keys():
			if dic[r]==1:
				ct+=1
		mxct=max(ct,mxct)
	mx.append(mxct)
sm=0
for k in mx:
	sm+=k
print(sm/len(s))