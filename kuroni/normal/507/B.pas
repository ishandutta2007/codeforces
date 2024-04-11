var r, x1, y1, x2, y2: int64;
    dist : real;
begin
    read(r, x1, y1, x2, y2);
    dist := sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if dist <> trunc(dist) then write(trunc((dist)/(2*r)) + 1)
    else if trunc(dist) mod (2*r) = 0 then write(trunc((dist)/(2*r))) else write(trunc((dist)/(2*r)) + 1);
end.