k=input()
cell=[]
cell.append([0,0])
cell.append([0,1])
cell.append([1,0])

for i in xrange(1,k+1):
	cell.append([i,i])
	cell.append([i,i+1])
	cell.append([i+1,i])
cell.append([k+1,k+1])

print len(cell)
for x in cell:
	print x[0],x[1]