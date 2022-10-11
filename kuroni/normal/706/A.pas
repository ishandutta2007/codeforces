uses math;
var a, b, v, x, y, n, i: longint;
    tmp: real;
begin
  read(a,b,n);
  read(x,y,v);
  tmp := (sqrt((x-a)*(x-a)+(y-b)*(y-b)))/v;
  for i := 2 to n do
  begin
    read(x,y,v);
    tmp := min(tmp,(sqrt((x-a)*(x-a)+(y-b)*(y-b)))/v);
  end;
  write(tmp);
end.