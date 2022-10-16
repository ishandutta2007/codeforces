import sys
normal = ["no", "great", "don't think so", "cool", "not bad", "don't touch me", "no", "no", "no", "no"]
grumpy = ["terrible", "worse", "go die in a hole", "are you serious", "don't even", "no", "no", "no", "no way", "no way"]
for i in range(10):
	print i
	sys.stdout.flush()
	s = raw_input()
	if s in normal and s not in grumpy:
		print "normal"
		sys.stdout.flush()
		break
	elif s in grumpy and s not in normal:
		print "grumpy"
		sys.stdout.flush()
		break

	normal.remove(s)
	grumpy.remove(s)