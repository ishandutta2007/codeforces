import sys
import math

f = sys.stdin

px,py,vx,vy,a,b,c,d = map(int, f.readline().split())

points = [[0,b],[-a/2.0,0],[-c/2.0,0],[-c/2.0,-d],[c/2.0,-d],[c/2.0,0],[a/2.0,0]]
angle = math.atan2(vy,vx)
angle -= math.pi / 2.0
if angle < -math.pi: angle += 2 * math.pi
for p in points:
	nx = p[0] * math.cos(angle) - p[1] * math.sin(angle)
	ny = p[0] * math.sin(angle) + p[1] * math.cos(angle)
	print nx+px, ny+py