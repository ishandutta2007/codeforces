uses math;

var d, h, v, e: longint;
    ans, area: real;

begin
  read(d,h,v,e);
  area := d * d / 4 * pi;
  if v / area <= e then write('NO')
  else
  begin
    ans := h/(v/area - e);
    writeln('YES');
    write(ans);
  end;
end.