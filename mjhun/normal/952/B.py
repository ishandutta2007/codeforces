import sys

def ask(x):
	print x
	sys.stdout.flush()
	return raw_input().split()

w=False

for i in range(4):
	s=ask(i)
	if 'great' in s or 'great!' in s or 'cool' in s or 'bad' in s or 'think' in s or 'touch' in s:
		print 'normal'
		w=True
		break
	if 'you' in s or 'are' in s or 'worse' in s or 'terrible' in s or 'way' in s or 'even' in s or 'die' in s or 'hole' in s:
		print 'grumpy'
		w=True
		break
	assert 'no' in s

if not w:
	print 'normal'