n=int(input())
tot=0
ss={"Tetrahedron":4,"Cube":6,"Octahedron":8,"Dodecahedron":12,"Icosahedron":20}
for _ in range(n):
    
    tot+=ss[input()]
print(tot)