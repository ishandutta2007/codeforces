k=int(input())
l=[]
for i in range(5,k//2+1):
    if k//i<i:
        break
    if k%i==0:
        l.append([i,k//i])
aa=[['a', 'e', 'i', 'o', 'u'],
    ['e', 'i', 'o', 'u', 'a'],
    ['i', 'o', 'u', 'a', 'e'],
    ['o', 'u', 'a', 'e', 'i'],
    ['u', 'a', 'e', 'i', 'o']]
if l==[]:
    print(-1)
else:
    a=l[0]
    b=['a']*a[1]
    gr=[b for i in range(a[0])]
    for i in range(5):
        #print(aa[i])
        gr[i]=aa[i]+gr[i][5:]
        #print(gr[i][:])
    #    print(gr)
    #print(gr)
    for i in range(5,a[0]):
        gr[i][:5]=aa[0]
    for i in range(5,a[1]):
        for j in range(5):
            gr[j][i]=aa[0][j]
    t=[''.join(i) for i in gr]
    e=''.join(t)
    print(e)
#print(l)
#print(gr)