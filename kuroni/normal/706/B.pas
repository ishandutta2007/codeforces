uses math;
var n, i, q, m: longint;
    A: array[1..100000] of int64;
procedure QuickSort(L,H:longint);
var i, j: longint;
    x, tmp: int64;
begin
  i := L;
  j := H;
  x := a[random(H-L+1)+L];
  repeat
    while A[i] < x do inc(i);
    while A[j] > x do dec(j);
    if i <= j then
    begin
      tmp := A[i];
      A[i] := A[j];
      A[j] := tmp;
      inc(i);
      dec(j);
    end;
  until i > j;
  if L < j then QuickSort(L,j);
  if i < H then QuickSort(i,H);
end;
function BinarySearch(X: longint): longint;
var L, H, mid: longint;
begin
  L := 1;
  H := n;
  while L <= H do
  begin
    mid := (L + H) div 2;
    if A[mid] <= X then L := mid + 1;
    if A[mid] > X then H := mid - 1;
  end;
  exit(L-1);
end;
begin
  read(n);
  for i := 1 to n do read(A[i]);
  QuickSort(1,n);
  read(q);
  for i := 1 to q do
  begin
    read(m);
    writeln(BinarySearch(m));
  end;
end.