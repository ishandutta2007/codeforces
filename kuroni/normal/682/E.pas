var n, a, b, c, i: longint;
    maxed: boolean;
    s: int64;
    X, Y: array[1..5000] of int64;

function area(a, b, c: longint): real;
begin
  exit(abs((x[b]-x[a])*(y[c]-y[a]) - (y[b]-y[a])*(x[c]-x[a])));
end;

begin
  read(n,S);
  for i := 1 to n do read(x[i],y[i]);
  a := 1; b := 2; c := 3;
  while true do
  begin
    maxed := true;
    for i := 1 to n do
    begin
      if area(i,b,c) > area(a,b,c) then begin a := i; maxed := false; end;
      if area(a,i,c) > area(a,b,c) then begin b := i; maxed := false; end;
      if area(a,b,i) > area(a,b,c) then begin c := i; maxed := false; end;
    end;
    if maxed then break;
  end;
  writeln(x[a] + x[b] - x[c],' ',y[a] + y[b] - y[c]);
  writeln(x[a] - x[b] + x[c],' ',y[a] - y[b] + y[c]);
  writeln(- x[a] + x[b] + x[c],' ',- y[a] + y[b] + y[c]);
end.