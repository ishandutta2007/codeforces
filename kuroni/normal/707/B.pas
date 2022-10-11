uses math;
var n, m, k, i: longint;
    A, S, E, U: array[1..100000] of longint;
    way, chk1, chk2: boolean;
    ans: int64;
procedure QuickSort(L, H: longint);
var i,j,x,tmp: longint;
begin
  i := L;
  j := H;
  x := A[random(H-L+1)+L];
  repeat
    while A[i] < x do inc(i);
    while A[j] > x do dec(j);
    if i <= j then
    begin
      tmp := A[i];
      A[i] := A[j];
      A[j] := tmp;
      inc(i);
      dec(j)
    end;
  until i>j;
  if L<j then QuickSort(L,j);
  if i<H then QuickSort(i,H);
end;

function Search(X: longint): boolean;
var L, H, mid: longint;
begin
  L := 1;
  H := k;
  while L <= H do
  begin
    mid := (L + H) div 2;
    if a[mid] = X then exit(true);
    if a[mid] < X then L := mid + 1 else H := mid - 1;
  end;
  exit(false);
end;
begin
  way := false;
  ans := 2147483647;
  read(n,m,k);
  for i := 1 to m do read(S[i],E[i],U[i]);
  for i := 1 to k do read(A[i]);
  QuickSort(1,k);
  for i := 1 to m do
  begin
    chk1 := Search(S[i]);
    chk2 := Search(E[i]);
    if ((chk1 or chk2) and not(chk1 and chk2)) then begin
      way := true;
      ans := min(ans,U[i]);
    end;
  end;
  if way then write(ans) else write(-1);
end.