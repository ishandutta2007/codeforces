import sys
import math

f = sys.stdin

l3,l4,l5 = map(int, f.readline().split())

def area(sides, length):
	R = 0.5 * length / math.sin(math.pi / sides)
	base = 0.5 * sides * R * R * math.sin(2.0 * math.pi / sides)
	height = math.sqrt(length*length - R*R)
	return base*height/3.0

print area(3,l3)+area(4,l4)+area(5,l5)