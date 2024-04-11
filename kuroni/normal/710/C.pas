var n, i, j: longint;
    A: array[1..49,1..49] of longint;
begin
  read(n);
  for i := 1 to n do for j := 1 to n do
  A[i,j] := n*((i+j-1+(n div 2)) mod n)+((i+2*j-2) mod n)+1;
  for i := 1 to n do
  begin
    for j := 1 to n do write(A[i,j],' ');
    writeln;
  end;
end.