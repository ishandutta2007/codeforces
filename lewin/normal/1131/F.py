n = int(raw_input())
class Node:

	def __init__(self, idx, head=None, tail=None, prev=None, next=None):
		self.head = head or self
		self.tail = tail or self
		self.prev = prev
		self.next = next
		self.idx = idx

ns = [Node(i) for i in xrange(n)]
p = [i for i in xrange(n)]

def par(x):
	if p[x] == x:
		return x
	p[x] = par(p[x])
	return p[x]

def join(a, b):
	a = par(a)
	b = par(b)

	x = ns[a]
	y = ns[b]

	p[b] = a
	ns[a].tail.next = ns[b].head
	ns[b].head.prev = ns[a].tail
	ns[a] = Node(ns[a].idx, ns[a].head, ns[b].tail, None, ns[a].head.next)

for __ in xrange(n-1):
	x, y = map(int, raw_input().split())
	x -= 1
	y -= 1
	join(x, y)

f = ns[par(0)]
r = []
while f != None:
	r.append(f.idx+1)
	f = f.next
print " ".join(map(str, r))