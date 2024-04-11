uses math;
var a : integer;
begin
    read(a);
    if a < 13 then write(round(intpower(2,a)))
    else write(8092 * round(intpower(2,a-13)))
end.