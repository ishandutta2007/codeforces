<?php

for(;;){
  $n = fgets(STDIN, 4096);
  if($n === false) break;
  $n = (integer)(trim($n));

  unset($up);
  for($i=0;$i<$n;$i++){
    $k = fgets(STDIN, 4096);
    $k = (integer)(trim($k));

    $up[$i] = $k - 1;
  }

  unset($depth);

  $mx = 0;
  for($i=0;$i<$n;$i++){
    $res = dfs($i, $up, $depth);
    if($mx < $res) $mx = $res;
  }

  echo $mx."\n";
}

function dfs($now, &$up, &$depth){
  if(isset($depth[$now])) return $depth[$now];
  if($up[$now] < 0) $depth[$now] = 1;
  else              $depth[$now] = dfs($up[$now], $up, $depth)+1;
  return $depth[$now];
}

?>